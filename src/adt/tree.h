/**
 *  ADT: Tree
 *  Implementation
 *
 *  http://github.com/kdzlvaids/algorithm
 */

#ifndef ALGORITHM_ADT_TREE_H_
#define ALGORITHM_ADT_TREE_H_ 1

#ifdef __cplusplus
extern "C"
{
#endif

#define ADT_TREE_KEY_TYPE       ADT_PAIR_KEY_TYPE
#define ADT_TREE_VALUE_TYPE     ADT_PAIR_VALUE_TYPE
typedef ADT_TREE_KEY_TYPE       ___key_type;
typedef ADT_TREE_VALUE_TYPE     ___value_type;
typedef adt_pair*               ___pair_type;

typedef size_t                  ___size_type;
typedef int                     ___boolean_type;
#ifndef FALSE
#   define FALSE    0
#endif
#ifndef TRUE
#   define TRUE     1
#endif

struct ___node
{
            ___pair_type        element_;
    struct  ___node*            left_;
    struct  ___node*            right_;
    struct  ___node*            parent_;
};

typedef struct  ___node         ___node_type;
typedef         ___node_type*   ___pointer;
typedef const   ___node_type*   ___const_pointer;

typedef         int                 ___compare_type;
typedef         ___compare_type     (* ___compare_func)(___value_type, ___value_type);

struct adt_tree
{
    ___size_type        size_;
    ___pointer          root_;
    ___compare_func     compare_;
};

typedef struct  adt_tree*       ___type;

___type
___create(const ___compare_func compare);

void
___destroy(___type tree);

___boolean_type
___empty(___type tree);

___size_type
___size(___type tree);

___pair_type
___find(___type tree, const ___key_type key);

void
___insert(___type tree, const ___pair_type pair);

void
___erase(___type tree, const ___key_type key);

void
___element_swap(___pointer first, ___pointer second);

___pointer
___node_successor(___type tree, const ___pointer node);

___pointer
___node_predecessor(___type tree, const ___pointer node);

void
___traverse_levelorder(___type tree, void (* do_something)(___pair_type));

void
___traverse_inorder(___type tree, void (* do_something)(___pair_type));

void
___traverse_preorder(___type tree, void (* do_something)(___pair_type));

void
___traverse_postorder(___type tree, void (* do_something)(___pair_type));

void
___traverse_inorder_using_node(___pointer node, void (* do_something)(___pair_type));

void
___traverse_preorder_using_node(___pointer node, void (* do_something)(___pair_type));

void
___traverse_postorder_using_node(___pointer node, void (* do_something)(___pair_type));

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_TREE_H_ */
