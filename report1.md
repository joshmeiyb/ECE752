# ECE 752 HW3 report

# Test machine - CSL machine
Intel Core i5-11500 Processor, due to the website https://ark.intel.com/content/www/us/en/ark/products/212277/intel-core-i511500-processor-12m-cache-up-to-4-60-ghz.html, the LLC size is 12MB

# Step
1. Run the command to get the infomation of cache size: `getconf -a | grep CACHE`
2. Results: 

```
LEVEL1_ICACHE_SIZE                 32768
LEVEL1_ICACHE_ASSOC                
LEVEL1_ICACHE_LINESIZE             64 
LEVEL1_DCACHE_SIZE                 49152
LEVEL1_DCACHE_ASSOC                12
LEVEL1_DCACHE_LINESIZE             64
LEVEL2_CACHE_SIZE                  524288
LEVEL2_CACHE_ASSOC                 8
LEVEL2_CACHE_LINESIZE              64
LEVEL3_CACHE_SIZE                  12582912
LEVEL3_CACHE_ASSOC                 16
LEVEL3_CACHE_LINESIZE              64
```

L1 Cache index size = 49152 / (12 * 64) = 64

L1 = 50 KB
L2 = 524 KB
L3 = 12 MB
