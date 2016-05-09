/**
 *
 *  ADT: Map
 *  Declaration
 *
 *  Required: tree.h
 *
 *  http://github.com/kdzlvaids/algorithm
 *
 */

#ifndef ALGORITHM_ADT_MAP_H_
#define ALGORITHM_ADT_MAP_H_ 1

#include "tree.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef adt_tree                        adt_map;
typedef int                             adt_map_boolean_type;
typedef adt_tree_pair_type              adt_map_pair_type;

#define adt_map_empty(map)              (adt_map_boolean_type)(map->front_ == NULL)
#define adt_map_size(map)               map->size_

#define adt_map_clear(map)              adt_tree_clear(map)
#define adt_map_insert(map, pair)       adt_tree_insert(map, pair)
#define adt_map_erase(map, key)         adt_tree_erase(map, key)

#define adt_map_count(map, key)         adt_tree_count(map, key)
#define adt_map_find(map, key)          adt_tree_find(map, key)

#define adt_map_create(compare)         adt_tree_create(compare)
#define adt_map_destroy(map)            adt_tree_destroy(map)

#define adt_map_traverse(map, callback) adt_tree_traverse_inorder(map, callback)

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_MAP_H_ */
