/**
 *
 *  ADT: Tree
 *  Declaration
 *
 *  http://github.com/kdzlvaids/algorithm
 *
 */

#ifndef ALGORITHM_ADT_TREE_H_
#define ALGORITHM_ADT_TREE_H_ 1

#ifdef __cplusplus
extern "C"
{
#endif

#define ADT_TREE_KEY_TYPE       ADT_PAIR_KEY_TYPE
#define ADT_TREE_VALUE_TYPE     ADT_PAIR_VALUE_TYPE
typedef ADT_TREE_KEY_TYPE       adt_tree_key_type;
typedef ADT_TREE_VALUE_TYPE     adt_tree_value_type;
typedef adt_pair*               adt_tree_pair_type;

typedef size_t                  adt_tree_size_type;
typedef int                     adt_tree_boolean_type;
#ifndef FALSE
#   define FALSE    0
#endif
#ifndef TRUE
#   define TRUE     1
#endif

struct adt_tree_node
{
            adt_tree_pair_type        element_;
    struct  adt_tree_node*            left_;
    struct  adt_tree_node*            right_;
    struct  adt_tree_node*            parent_;
};

typedef struct  adt_tree_node         adt_tree_node_type;
typedef         adt_tree_node_type*   adt_tree_pointer;
typedef const   adt_tree_node_type*   adt_tree_const_pointer;

typedef         int                 adt_tree_compare_type;
typedef         adt_tree_compare_type     (* adt_tree_compare_func)(adt_tree_value_type, adt_tree_value_type);

struct adt_tree_adt_tree
{
    adt_tree_size_type        size_;
    adt_tree_pointer          root_;
    adt_tree_compare_func     compare_;
};

typedef struct  adt_tree_adt_tree*       adt_tree;

adt_tree
adt_tree_create(const adt_tree_compare_func compare);

void
adt_tree_destroy(adt_tree tree);

void
adt_tree_postorder_traverse_for_destroy(adt_tree_pointer node);

adt_tree_boolean_type
adt_tree_empty(adt_tree tree);

adt_tree_size_type
adt_tree_size(adt_tree tree);

adt_tree_pair_type
adt_tree_find(adt_tree tree, const adt_tree_key_type key);

void
adt_tree_insert(adt_tree tree, const adt_tree_pair_type pair);

void
adt_tree_erase(adt_tree tree, const adt_tree_key_type key);

void
adt_tree_element_swap(adt_tree_pointer first, adt_tree_pointer second);

adt_tree_pointer
adt_tree_node_successor(adt_tree tree, const adt_tree_pointer node);

adt_tree_pointer
adt_tree_node_predecessor(adt_tree tree, const adt_tree_pointer node);

void
adt_tree_traverse_levelorder(adt_tree tree, void (* do_something)(adt_tree_pair_type));

void
adt_tree_traverse_inorder(adt_tree tree, void (* do_something)(adt_tree_pair_type));

void
adt_tree_traverse_preorder(adt_tree tree, void (* do_something)(adt_tree_pair_type));

void
adt_tree_traverse_postorder(adt_tree tree, void (* do_something)(adt_tree_pair_type));

void
adt_tree_traverse_inorder_using_node(adt_tree_pointer node, void (* do_something)(adt_tree_pair_type));

void
adt_tree_traverse_preorder_using_node(adt_tree_pointer node, void (* do_something)(adt_tree_pair_type));

void
adt_tree_traverse_postorder_using_node(adt_tree_pointer node, void (* do_something)(adt_tree_pair_type));

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_TREE_H_ */
