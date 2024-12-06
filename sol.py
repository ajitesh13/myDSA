

class Spreadsheet:
    def __init__(self):
        self.mapper = {}
    
    def set(self, key, value):
        if value == "":
            if key in self.mapper:
                del self.mapper[key]
            return
        self.mapper[key] = value
    
    def get(self):
        result = []
        for key, raw_val in self.mapper.items():
            computed_val = self.evaluate(key)
            result.append((key, raw_val, computed_val))
        
        return result
    
    def evaluate(self, key):
        if key not in self.mapper:
            return 0

        value = self.mapper[key]
        if not value.startswith('='):
            return int(value)
        
        value = value[1:]
        num1, num2 = value.split("+")

        def get_value(token):
            return int(token) if token.isdigit() else self.evaluate(token)
        
        return get_value(num1) + get_value(num2)

sheet = Spreadsheet()
sheet.set("A1", "5")
sheet.set("B1", "=20+1")
sheet.set("A1", "-9")
sheet.set("A3", "")
sheet.set("A3", "1")
sheet.set("A3", "")
sheet.set("A3", "=A1+B1")
sheet.set("A4", "=A3+B1")
sheet.set("A5", "=A3+A4")
sheet.set("A1", "4")
sheet.set("A6", "=42+A1")
results = sheet.get()
for result in results:
    print(result)

            