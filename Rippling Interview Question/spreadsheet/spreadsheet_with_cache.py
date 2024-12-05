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
        cache = {}
        result = []
        for key, raw_val in self.mapper.items():
            computed_val = self.evaluate(key, cache)
            result.append((key, raw_val, computed_val))
        
        return result
    
    def evaluate(self, key, cache):
        if key not in self.mapper:
            return 0
        
        if key in cache:
            return cache[key]
        
        value = self.mapper[key]
        if value[0] != "=":
            result = int(value)
            cache[key] = result
            return result
        
        value = value[1:]
        num1, num2 = value.split("+")

        def get_value(token):
            return int(token) if token.isdigit() else self.evaluate(token, cache)
        
        result = get_value(num1) + get_value(num2)
        cache[key] = result
        return result

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