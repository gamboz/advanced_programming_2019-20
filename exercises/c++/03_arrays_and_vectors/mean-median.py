import pandas as pd

df = pd.read_csv("temperatures.txt", header=None)
print(df.describe())
print(df.median())
