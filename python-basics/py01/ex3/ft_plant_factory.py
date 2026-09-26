class Plant:
    all_plants = []

    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age_days = age
        
        Plant.all_plants.append(self)


    def age(self):
        self.age_days += 1

    def show(self):
        print(f"Created: {self.name}: {round(self.height, 1)}cm, {self.age_days} days old")

    @classmethod
    def factory_output(cls):
        print("=== Plant Factory Output ===")
        for plant in cls.all_plants:
            plant.show()

if __name__ == "__main__":
    plant1 = Plant("Rose", 25.0, 30)
    plant2 = Plant("Oak", 200.0, 365)
    plant3 = Plant("Cactus", 5.0, 90)
    plant4 = Plant("Sunflower", 80.0, 45)
    plant5 = Plant("Fern", 15.0, 120)

    Plant.factory_output()
