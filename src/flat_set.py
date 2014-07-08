import flat_set
import time
import sys
import random
from random import choice

def test():
    sset = flat_set.Flat_set()
    elts = []

    print "\033[1;32mTest method of the flat_set from c++:\n"
    print "\033[1;32mAdd some elements in the set: \033[0m"
    for i in range(0,19):
        e = random.randint(0,1000)
        if sset.insert(str(e)):
            elts.append(str(e))
    sset.insert(str(999))
    sset.draw()

    print
    print "\033[1;32mFind elements in the set: \033[0m"
    for i in range(0,4):
        ch = choice(elts)
        print "\033[1;34mFind \033[0m" + ch + " " + ("\033[1;32mTrue" if sset.find(ch) else "\033[31mFalse") + "\033[0m"
        chn = random.randint(0,1000)
        print "\033[1;34mFind \033[0m" + str(chn) + " " + ("\033[1;32mTrue" if sset.find(str(chn)) else "\033[31mFalse") + "\033[0m"

    print
    print "\033[1;32mSize of the set: \033[0m" + str(sset.size())

    sset.clear()
    print "\033[1;32mSize after clear the set: \033[0m" + str(sset.size())


def bench():
    sset = flat_set.Flat_set()
    pset = set()
    elts = []

    print "\033[1;34mSome bench to find an element in a set: \033[0m"

    for i in range(0,100) :
        e = random.randint(0,500)
        pset.add(str(e))
        if sset.insert(str(e)):
            elts.append(str(e))
    for i in range(0,3):
        ch = choice(elts)

        print "\033[1;34mTime to find " + ch + ": \033[0m"
        debut = time.time()

        sset.find(ch)

        fin = time.time()

        print "\033[1;32mFlat_set\033[0m Execution time: " + str(fin - debut)

        debut = time.time()

        ch in pset

        fin = time.time()

        print "\033[31mPython\033[0m Execution time: " + str(fin - debut)

def main():
    if len(sys.argv) > 1:
        bench()
    else:
        test()

if __name__ == "__main__":
    main()
