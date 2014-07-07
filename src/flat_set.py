import flat_set

sset = flat_set.Flat_set()
pset = set()

for i in range(0,10) :
    sset.insert(str(i))
    pset.add(str(i))

print pset
print sset

