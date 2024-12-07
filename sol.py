class Spreadsheet:

    def __init__(self):
        self.map = {}
        self.cache = {}

    def set(self, key, value):
        if value == "":
            if key in self.map:
                del self.map[key]
        
        self.map[key] = value
    
    def print_sheet(self):

        for key, raw_value in self.map.items():
            value = self.evaluate(key)
            print(f"{key}: {raw_value} ${value}")
    
    def evaluate(self, key):

        if key not in self.map:
            return 0

        if key in self.cache:
            return self.cache[key]
        
        value = self.map[key]
        if value[0] != "=":
            self.cache[key] = int(value)
            return self.cache[key]
        
        value = value[1:]   
        num1, num2 = value.split('+')

        def get_value(token):
            return int(token) if token.isdigit() else self.evaluate(token)

        self.cache[key] = get_value(num1) + get_value(num2)
        return self.cache[key]

sheet = Spreadsheet()
sheet.set("A1", '=8+2')
sheet.set("A2", '=3+4')
sheet.set("A3", '=11+8')
sheet.set("A4", '=A1+9')
sheet.set("A5", '=A3+A4')

sheet.print_sheet()

