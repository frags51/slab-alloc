#include "libmymem.hpp"
#include <iostream>
#include <sys/mman.h>
#define DEB // For debugging purpose.
/**
 * An array of all buckets.
 * Each stores object of size 2^(index+2)
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

int bestFit(unsigned size){
	if(size<=4) return 0;
	else if(size <=8) return 1;
	else if(size <=16) return 2;
	else if(size <=32) return 3;
	else if(size <=64) return 4;
	else if(size <=128) return 5;
	else if(size <=256) return 6;
	else if(size <=512) return 7;
	else if(size <=1024) return 8;
	else if(size <=2048) return 9;
	else if(size <=4096) return 10;
	else if(size <=8192) return 11;
	else return -1;
} // best fit

void *mymalloc(unsigned size){
	int index = bestFit(size);
	if(index<0) {
		#ifdef DEB
			std::cerr<<"Index < 0 bestFit"<<std::endl;
		#endif
		return nullptr;
	}

	if(hashTable[index].firstSlab==nullptr){ // First slab of the size.
		slab_t *slbPtr = (slab_t *) mmap(NULL, 1<<16, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		hashTable[index].firstSlab = slbPtr;
		// Initialize slab variables.
		slbPtr->thisBucket = &(hashTable[index]);
		slbPtr->totObj = (slbPtr->thisBucket)->totObj;
		slbPtr->freeObj = slbPtr->totObj;
		slbPtr->nextSlab = nullptr;
		slbPtr->bitmap.reset();
		// Give first object.
		// var is the first free object's location.
		slbPtr->freeObj--;
		slbPtr->bitmap[0]=1;
		// Need to jump by 1 byte * sizeof(slab_t)
		// Need to store sizeof(pointer) in this location.
		slab_t **p2 = (slab_t **)(slbPtr+1);
		#ifdef DEB
			std::cerr<<"slbPtr: "<<slbPtr<<", p2: "<<p2<<", p2+1: "<<p2+1<<std::endl;
		#endif
		*p2 = slbPtr;
		return (void *)(p2+1);
	}
	else if(true){

	}
} // myalloc

int main(){
	mymalloc(4);
	return 0;
}