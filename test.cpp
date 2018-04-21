#include <iostream>
#include <bitset>
struct slab_t{
	unsigned totObj;
	unsigned freeObj;
	struct bucket_t *thisBucket;
	slab_t * nextSlab;
	std::bitset<1<<13> bitmap;
};


struct object_t{
	slab_t * slab;
	char a[1<<2]; 	
};

/**
 * Stores size of the objects and a pointer to the first slab in that bucket.
 */
struct bucket_t{
	unsigned objSize;
	slab_t * firstSlab;
};


bucket_t hashTable[] = {
	bucket_t{4, nullptr},
	bucket_t{8, nullptr},
	bucket_t{16, nullptr},
	bucket_t{32, nullptr},
	bucket_t{64, nullptr},
	bucket_t{128, nullptr},
	bucket_t{256, nullptr},
	bucket_t{512, nullptr},
	bucket_t{1024, nullptr},
	bucket_t{1<<11, nullptr},
	bucket_t{1<<12, nullptr},
	bucket_t{1<<13, nullptr},
};

using namespace std;
int main(){

	cout<<sizeof(slab_t)<<endl;
	
	return 0;
}