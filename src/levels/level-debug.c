#include "../level-utils.h"
#include <stdlib.h>

Level_t *DebugLevel() {
  Level_t *level_debug = malloc(sizeof(Level_t));
  level_debug->id = LEVEL_DEBUG;
  level_debug->loaded = false;

  Object_t sphere;
  sphere.mesh = GenMeshSphere(1.0f, 10, 10);
  sphere.model = LoadModelFromMesh(sphere.mesh);
  sphere.center = (Vector3){0.0f, 5.0f, 0.0f};
  sphere.bound_box = GetModelBoundingBox(sphere.model);

  Object_t floor;
  floor.mesh = GenMeshPlane(20, 20, 5, 5);
  floor.model = LoadModelFromMesh(floor.mesh);
  floor.center = (Vector3){0.0f, 0.0f, 0.0f};
  floor.bound_box = GetModelBoundingBox(floor.model);

  level_debug->obj_num = 2;
  level_debug->objects = malloc(sizeof(Object_t) * level_debug->obj_num);
  level_debug->objects[0] = sphere;
  level_debug->objects[1] = floor;
  return level_debug;
}
