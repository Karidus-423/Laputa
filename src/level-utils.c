#include "level-utils.h"
#include "utils.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

Level_t *LoadLevel(level_id selected) {
  Level_t *load;
  printf("Loading level.....\n");
  switch (selected) {
  case LEVEL_DEBUG:
    load = DebugLevel();
    if (load != NULL) {
      load->loaded = true;
      printf("Loaded Level!\n");
    }
    break;
  case LEVEL_ONE:
    break;
  }
  if (load == NULL) {
    printf("Unable to load level %d\n", selected);
    perror("Level load error\n");
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
      printf("Unloaded level succesfully\n");
    } else {
      printf("Level is not loaded for it to unload\n");
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
