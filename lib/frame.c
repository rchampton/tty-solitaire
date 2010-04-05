#include <malloc.h>
#include "frame.h"

void allocate_frame(struct frame **frame) {
  *frame = malloc(sizeof(**frame));

  return;
}

void initialize_frame(struct frame *frame) {
  frame->shape   = NULL;
  frame->height  = FRAME_HEIGHT;
  frame->width   = FRAME_WIDTH;
  frame->start_y = 0;
  frame->start_x = 0;

  return;
}

void delete_frame(struct frame *frame) {
  delwin(frame->shape);
  free(frame);

  return;
}

void set_frame(struct frame *frame, int start_y, int start_x) {
  frame->start_y = start_y;
  frame->start_x = start_x;
  frame->shape = newwin(frame->height,
                        frame->width,
                        frame->start_y,
                        frame->start_x);

  return;
}
