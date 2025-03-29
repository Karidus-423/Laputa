#include "../level-utils.h"
#include <raylib.h>
#include <stdlib.h>

Level_t *DebugLevel() {
  Level_t *level_debug = malloc(sizeof(Level_t));
  level_debug->id = LEVEL_DEBUG;
  level_debug->loaded = false;

  Object_t ico_sphere1 = {
      .mesh = GenMeshSphere(2.3, 6, 6),
      .model = LoadModelFromMesh(ico_sphere1.mesh),
      .center = (Vector3){0.0f, 8.0f, -12.0f},
  };

  Object_t ico_sphere2 = {
      .mesh = GenMeshSphere(2.3, 6, 6),
      .model = LoadModelFromMesh(ico_sphere1.mesh),
      .center = (Vector3){-10.0f, 5.0f, -3.0f},
  };

  level_debug->obj_num = 2;
  level_debug->objects = malloc(sizeof(Object_t) * level_debug->obj_num);
  level_debug->objects[0] = ico_sphere1;
  level_debug->objects[1] = ico_sphere2;
  return level_debug;
}
