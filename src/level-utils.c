#include "level-utils.h"
#include "utils.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

Level_t *LoadLevel(level_id selected) {
  Level_t *load;
  switch (selected) {
  case LEVEL_DEBUG:
    load = DebugLevel();
    if (load != NULL) {
      load->loaded = true;
    }
    break;
  case LEVEL_ONE:
    break;
  }
  if (load == NULL) {
    TraceLog(LOG_ERROR, "Unable to load level %d", selected);
  } else {
    TraceLog(LOG_INFO, "LEVEL: [ID %d] Level loaded successfully", selected);
  }
  return load;
};

void UnloadLevel(Level_t *level) {
  if (level != NULL) {
    if (level->loaded == true) {
      if (level->objects != NULL) {
        free(level->objects);
      }
      free(level);
      TraceLog(LOG_INFO, "LEVEL: [ID %d] Level unloaded successfully",
               level->id);
    } else {
      TraceLog(LOG_WARNING, "LEVEL: [ID %d] Level not unloaded successfully",
               level->id);
    }
  } else {
    printf("Passed Level ptr == NULL\n");
  }
};

void DrawLevel(Level_t *level) {
  Object_t *objects = level->objects;
  for (int i = 0; i < level->obj_num; i++) {
    DrawModel(objects[i].model, objects[i].center, 1.0f, BLACK);
    DrawModelWires(objects[i].model, objects[i].center, 1.0f, WHITE);
  }
}
