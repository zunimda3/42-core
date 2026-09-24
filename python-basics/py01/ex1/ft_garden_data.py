class Plant:
    all_plants = []

    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age
        
        Plant.all_plants.append(self)

    @classmethod
    def show(cls):
        print("=== Garden Plant Registry ===")
        for plant in cls.all_plants:
            print(f"{plant.name}: {plant.height}cm, {plant.age} days old")

if __name__ == "__main__":
    plant1 = Plant("Rose", 25, 30)
    plant2 = Plant("Sunflower", 80, 45)
    plant3 = Plant("Cactus", 15, 120)

    Plant.show()
