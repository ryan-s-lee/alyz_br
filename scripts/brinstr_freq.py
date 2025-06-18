from collections import defaultdict
import sys
from tqdm import tqdm
from itertools import islice

freq_map = defaultdict(int)
counter = 100
with open(sys.argv[1]) as inf:
        for line in tqdm(inf):
            entries = line.split()
            for entry in entries:
                first = entry.split("/")[0]
                freq_map[first] += 1

top_n = 30
sorted_map = {k:v for k, v in islice(reversed(sorted(freq_map.items(), key=lambda item: item[1])), 30)}
print(sorted_map)
