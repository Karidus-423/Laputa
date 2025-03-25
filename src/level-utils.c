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
    printf("Unable to load level %d\n", selected);
    perror("Level load error\n");
  } else {
    printf("INFO: LEVEL: [ID %d] Level loaded successfully\n", selected);
  }
  return load;
};

void UnloadLevel(Level_t *level) {
  printf("INFO: LEVEL: [ID %d] Level unloaded ", level->id);
  if (level != NULL) {
    if (level->loaded == true) {
      if (level->objects != NULL) {
        free(level->objects);
      }
      free(level);
      printf("success\n");
    } else {
      printf("failure\n");
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
