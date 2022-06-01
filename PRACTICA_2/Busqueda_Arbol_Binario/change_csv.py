import os

numbers = [1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000]

for n in numbers:
    print(f"mv sal_{n}.txt sal_{n}.csv")
    os.system(f"mv sal_{n}.txt sal_{n}.csv")