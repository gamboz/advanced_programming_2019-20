#!/usr/bin/env python
import unittest


class Sequence():
    def __init__(self, iterable):
        self.iterable = list(iterable)
        self.indice = 0

    def __str__(self):
        return ", ".join((str(x) for x in self.iterable))

    def __len__(self):
        return len(self.iterable)

    def __eq__(self, other):
        if len(self.iterable) != len(other):
            return False

        # hmmm...
        for i in range(len(other)):
            if self.iterable[i] != other[i]:
                return False
        return True

    def __getitem__(self, i):
        print("inside getitem")
        return self.iterable[i]

    def __setitem__(self, key, value, /):
        self.iterable[key] = value

    def __delitem__(self, key):
        del self.iterable[key]

    def __iter__(self):
        print("inside Sequence.__iter__")
        self.indice = 0
        return self

    def __next__(self):
        print('inside next')
        if self.indice >= len(self.iterable):
            raise StopIteration
        self.indice += 1
        return self.iterable[self.indice-1]

    def __copy__(self):
        import copy
        return copy.deepcopy(self.iterable)


__all__ = [Sequence, ]


class TestStaRoba(unittest.TestCase):
    "vedi excercise 02"

    # def test_constructor(self):
    #     self.assertTrue(Sequence(range(10)) is not None, "point 1")

    # def test_print(self):
    #     s = Sequence(range(10))
    #     self.assertEqual(str(s), "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", "point 2")

    # def test_length(self):
    #     s = Sequence(range(10))
    #     self.assertEqual(len(s), 10, "point 3")

    # def test_equality(self):
    #     s = Sequence(range(10))
    #     self.assertTrue(s == (0, 1, 2, 3, 4, 5, 6, 7, 8, 9), "point 4")

    # def test_subscript(self):
    #     s = Sequence(range(10))
    #     self.assertTrue(s[0] == 0, "point 5")
    #     self.assertTrue(s[7] == 7, "point 5")
    #     self.assertTrue(s[-1] == 9, "point 5")

    # def test_set(self):
    #     s = Sequence(range(10))
    #     self.assertTrue(s[7] == 7, "point 6")
    #     s[7] = 77
    #     self.assertTrue(s[7] == 77, "point 6")

    # def test_del(self):
    #     s = Sequence(range(10))
    #     self.assertTrue(s[7] == 7, "point 7")
    #     del s[1:4:2]
    #     self.assertTrue(len(s) == 8, "point 7")
    #     self.assertTrue(s[0] == 0, "point 7")
    #     self.assertTrue(s[1] == 2, "point 7")
    #     self.assertTrue(s[2] == 4, "point 7")

    # hmmm...
    def test_iter(self):
        s = Sequence(range(10))
        for i in s:
            print(f"{i}-{s}")
            #self.assertTrue(s[i] == i, "point 8")

        self.assertTrue(True)
    # def test_copy(self):
    #     import copy
    #     s1 = Sequence(range(10))
    #     s2 = copy.copy(s1)
    #     self.assertFalse(s1 is s2)
    #     self.assertTrue(s1 == s2, "shallow copy failed")
    #     self.assertTrue(False, "come testo un deepcopy di una lista di interi???")

if __name__ == "__main__":
    # print("should be testing")
    unittest.main()
