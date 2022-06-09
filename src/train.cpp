// Copyright 2021 NNTU-CS
#include "train.h"
void Train::addCage(bool light) {
  Cage* cell = new Cage;
  cell->next = nullptr;
  cell->prev = nullptr;
  cell->light = light;
  if (!first) {
  first = cell;
  end = first;
  } else {
  end->next = cell;
  end->next->prev = end;
  end = end->next;
  if (!end->next) {
  end->next = first;
  } else { first-prev = end; }
  }
}

int Train::getLength() {
  int count = 0;
  Cage* tmp = first;
  if (!(tmp->light)) {
  tmp->light = !(tmp->light);
  }
  tmp->light = true;
  while (tmp) {
    count++;
    countOp++;
    tmp = tmp->next;
    if (tmp->light == true) {
    tmp->light = false;
    }
  }
  for (int i = 0; i < count; i++) {
    countOp++;
    tmp = tmp->prev;
  }
  if (tmp->light == false) {
  return count;
  }
  return getLenght();
}

int Train::getOpCount() {
  return countOp;
}
