#!/usr/bin/env python

lista = ['ab', 'ca', 'bc']
# expect ca ab bc

ordered_lista = sorted(lista, key=lambda x: x[::-1])

print(f"lista is ordered_lista? {lista is ordered_lista}")
print(f"lista: {lista}")
print(f"ordered_lista: {ordered_lista}")
