#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


intarr_t* intarr_create(unsigned int len){
  intarr_t *wow = malloc(sizeof(intarr_t));
  if(wow == 0){
    return NULL;
  }
  wow->data = malloc(len*sizeof(int));
  if(wow->data == 0){
    free(wow);
    return NULL;
  }
  wow->len = len;
  return wow;
} // GOOD

void intarr_destroy(intarr_t* ia){
  if(ia != NULL && ia->data != NULL){
    free(ia->data);
    free(ia);
  }
} // GOOD

intarr_result_t intarr_set( intarr_t* ia, unsigned int index, int val){
  if(ia == NULL){
    return INTARR_BADARRAY;
  }
  if(index <= ia->len){
    ia->data[index] = val;
    return INTARR_OK;
  }
  else{
    return INTARR_BADINDEX;
  }
} // GOOD

intarr_result_t intarr_get(const intarr_t* ia, unsigned int index, int* i){
  if(ia == NULL){
    return INTARR_BADARRAY;
  }
  if(index <= ia->len && i != NULL){
    *i = ia->data[index];
    return INTARR_OK;
  }
  else{
    *i = *i;
    return INTARR_BADINDEX;
  }
} // GOOD

intarr_t* intarr_copy(const intarr_t* ia){
  intarr_t *wow = malloc(sizeof(intarr_t));
  if(wow == 0){
    return NULL;
  }
  wow->data = malloc(ia->len*sizeof(int));
  if(wow->data == 0){
    free(wow);
    return NULL;
  }
  wow->len = ia->len;
  memcpy(wow->data,ia->data,wow->len*sizeof(int));
  return wow;
} // GOOD

intarr_result_t intarr_sort(intarr_t* ia){
  if(ia == NULL){
    return INTARR_BADARRAY;
  }
  if(ia == NULL){
        return INTARR_BADARRAY;
    }
    else{
        int minpos,i,j,tmp;
        int x = ia->len;
        for(j=0;j< (x-1);j++){
            minpos = j;
            for(i=j+1;i < x;i++){
                if(ia->data[i] < ia->data[minpos]){
                    minpos = i;
                }
            }
            tmp = ia->data[minpos];
            ia->data[minpos] = ia->data[j];
            ia->data[j] = tmp;
        }
    }
    return INTARR_OK;
} // GOOD

intarr_result_t intarr_find(intarr_t* ia, int target,int* i){
  if(ia == NULL){
    return INTARR_BADARRAY;
  }
  for(unsigned int Trump = 0;Trump < (ia->len);Trump++){
    if(target == ia->data[Trump] && i != NULL){
      *i = Trump;
      return INTARR_OK;
    }
  }
  *i = *i;
  return INTARR_NOTFOUND;
} // GOOD

intarr_result_t intarr_push(intarr_t* ia, int val){
  if(ia == NULL){
    return INTARR_BADARRAY;
  }
  ia->len++;
  ia->data = realloc(ia->data,(ia->len)*sizeof(int));
  ia->data[ia->len-1] = val;
  if(ia->data[ia->len-1] == val){
    return INTARR_OK;
  }
  else{
    return INTARR_BADALLOC;
  }
} //GOOD

intarr_result_t intarr_pop(intarr_t* ia, int *i){
  if(ia == NULL){
    return INTARR_BADARRAY;
  }
  if(ia->len == 0){
    return INTARR_BADINDEX;
  }
  if(i != NULL){
    *i = ia->data[ia->len-1];
    ia->data[ia->len-1] = 0;
    ia->data = realloc(ia->data,(ia->len-1)*sizeof(int));
    ia->len--;
  }
  return INTARR_OK;
}// GOOD

intarr_result_t intarr_resize(intarr_t* ia, unsigned int newlen){
  if(ia == NULL){
    return INTARR_BADARRAY;
  }
  int len = newlen;
  ia->data = realloc(ia->data,len*sizeof(int));
  if(ia->data == 0){
    return INTARR_BADALLOC;
  }
  ia->len = newlen;
  int og_len = ia->len;
  if(len > og_len){
    for(int i = og_len; i < len; i++){
      ia->data[i] = 0;
    }
  }
  return INTARR_OK;
}// GOOD

intarr_t* intarr_copy_subarray(intarr_t* ia, unsigned int first, unsigned int last){
  if(ia == NULL || 
    first >= ia->len || 
    last >= ia->len || 
    last < first){
    return NULL;
}
  intarr_t *wow = malloc(sizeof(intarr_t));
  if(wow == 0){
    return NULL;
  }
  size_t Jesus = (last-first) + 1;
  wow->data = malloc(Jesus*sizeof(int));
  if(wow->data == 0){
    free(wow);
    return NULL;
  }
  wow->len = Jesus;
  if(wow->len == 0){
    free(wow);
    return NULL;
  }
  unsigned int j = 0;
  for(unsigned int i = first; i <= last; ++i){
    wow->data[j] = ia->data[i];
    j++;
  }
  return wow;
}//GOOD
