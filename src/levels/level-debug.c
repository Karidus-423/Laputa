#include "../level-utils.h"
#include <raylib.h>
#include <stdlib.h>

Level_t *DebugLevel() {
  Level_t *level_debug = malloc(sizeof(Level_t));
  level_debug->id = LEVEL_DEBUG;
  level_debug->loaded = false;

  Model blender_export = LoadModel("./assets/models/levels/level-debug.obj");
  Object_t level;
  level.model = blender_export;
  level.center = (Vector3){0.0f, 0.0f, 0.0f};

  level_debug->obj_num = 1;
  level_debug->objects = malloc(sizeof(Object_t) * level_debug->obj_num);
  level_debug->objects[0] = level;
  return level_debug;
}
