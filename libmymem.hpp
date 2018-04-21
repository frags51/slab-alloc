#ifndef _LIB_MYMEM_HPP
#define _LIB_MYMEM_HPP

#include <bitset>

/**
 * OS slab allocator assignment.
 */

/**
 * The function to be exported in the API.
 * @param size How many bytes to allocate? [description]
 * @return      Pointer to the allocated memory.
 */
void *mymalloc(unsigned size);
void myfree(void *ptr);

struct slab_t{
	struct bucket_t *thisBucket;
	unsigned totObj;
	unsigned freeObj;
	slab_t * nextSlab;
	std::bitset<1<<13> bitmap; // Fixed size bitmap. 	
};


struct object_t{
	slab_t * slab;
	 	
};


struct bucket_t{
	unsigned objSize;
	unsigned totObj;
	slab_t * firstSlab;
};
/**
 * An array of all buckets.
 * Each stores object of size 2^(index+1)
 */
bucket_t hashTable[] = { /* 12 Elements */
	bucket_t{4, 5363, nullptr},
	bucket_t{8, 4022, nullptr},
	bucket_t{16, 2681,nullptr},
	bucket_t{32, 1609,nullptr},
	bucket_t{64, 893, nullptr},
	bucket_t{128, 473, nullptr},
	bucket_t{256, 243, nullptr},
	bucket_t{512, 123, nullptr},
	bucket_t{1024, 62, nullptr},
	bucket_t{1<<11, 31, nullptr},
	bucket_t{1<<12, 15, nullptr},
	bucket_t{1<<13, 7, nullptr},
};


#endif /* _LIB_MYMEM_HPP */