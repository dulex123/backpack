# Python cheatsheet
We use dictionaries when we need lookup table with unique keys.

## Dictionaries
```python
europe = {'spain':'madrid', 'france':'paris', 'germany':'berlin'}
europe.keys()           # returns spain,france,germany

# Keys have to be immutable, list cannot be a key

del(europe['spain'])    # removes key-value pair for key spain
'spain' in europe       # asserts if key is inside dict (boolean)

# With nested dictionaries chain rule applies for data retrieval
europe = {
    'spain': {'capital':'madrid', 'population':46.77},
    'france': {'capital':'rome', 'population':66.03} }

print(europe['spain']['capital'])   # returns madrid

```

## Pandas
Defacto standard for tabular data in python. Higher level abstraction than numpy. Used for data sci.

### Dataframe from dictionary

```python
import pandas as pd
countries = {
    "country":      ["Brazil","Russia","India"],
    "capital":      ["Brasilia","Moscow","New Delhi"],
    "area":         [8.516, 17.10, 3.28],
    "population":   [200.4, 143.5, 1252]
}

brics = pd.DataFrame(countries)

# By default indexes are 0, 1, 2... we can change this to
brics.index = ["BR", "RU", "IN"]
```

### Dataframe from CSV file

```python
import pandas as pd

# If we want, we can set read_csv() parameter index_col=0 if index column is first column within csv file
brics = pd.read_csv("path/to/brics.csv", index_col=0)

print(brics['country'])             # Pandas series
print(brics[['country']])           # Pandas DataFrame
print(brics[['country','capital']]) # two columns, Pandas DataFrame
print(brics[0:3])                   # Prints out first 3 observations
```

