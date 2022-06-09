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
  } else { first->prev = end; }
  }
}

int Train::getLength() {
  int count = 0;
  while (first) {
    Cage* tmp = first;
    first->light = true;
    while (true) {
      tmp = tmp->next;
      count++;
      countOp++;
      if (tmp->light == true) {
        tmp->light = false;
        for (int i = 0; i < count; i++) {
          tmp = tmp->prev;
          countOp++;
        }
        if (tmp->light == false) {
          return count;
        }
        count = 0;
      }
    }
  }
  return 0;
}

int Train::getOpCount() {
  return countOp;
}
