#ifndef LEVEL_UTILS
#define LEVEL_UTILS

#include "utils.h"
typedef enum levels {
  LEVEL_DEBUG,
  LEVEL_ONE,
} level_id;

typedef struct level_opts {
  int obj_num;
  bool loaded;
  Object_t *objects;
  level_id id;
} Level_t;

Level_t *LoadLevel(level_id selected);
void DrawLevel(Level_t *level);
void UnloadLevel(Level_t *level);

Level_t *DebugLevel();

#endif
