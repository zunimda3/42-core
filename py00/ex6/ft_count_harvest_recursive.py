def count_harvest(days_until_harvest: int):
    if days_until_harvest > 1:
        count_harvest(days_until_harvest - 1)
    print(f"Day {days_until_harvest}")
    
def ft_count_harvest_recursive():
    days_until_harvest: int = int(input("Days until harvest: "))
    count_harvest(days_until_harvest)
    print("Harvest time!")

if __name__ == "__main__":
    ft_count_harvest_recursive()
