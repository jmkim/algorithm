/**
 *  ADT: Pair
 *  Implementation
 *
 *  http://github.com/kdzlvaids/algorithm
 */

#ifndef ALGORITHM_ADT_PAIR_H_
#define ALGORITHM_ADT_PAIR_H_ 1

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef ADT_PAIR_KEY_TYPE
#define ADT_PAIR_KEY_TYPE       void*
#endif

#ifndef ADT_PAIR_VALUE_TYPE
#define ADT_PAIR_VALUE_TYPE     void*
#endif

typedef ADT_PAIR_KEY_TYPE       adt_pair_key_type;
typedef ADT_PAIR_VALUE_TYPE     adt_pair_value_type;

struct ___adt_pair
{
    adt_pair_key_type       first;
    adt_pair_value_type     second;
};

typedef struct  ___adt_pair     adt_pair;

#ifdef __cplusplus
}
#endif

#endif /* ! ALGORITHM_ADT_PAIR_H_ */
