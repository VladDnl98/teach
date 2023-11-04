MIN_LATITUDE = 50
MAX_LATITUDE = 80
MIN_LONGITUDE = 20
MAX_LONGITUDE = 45

with open('coordinates.txt', 'r') as file:
    data = file.read()

coordinates = data.split('\n')

for coordinate in coordinates:
    coordinate = coordinate.replace('(', '').replace(')', '').replace(',', '')
    latitude, longitude = coordinate.split()
    latitude = float(latitude)
    longitude = float(longitude)

    if MIN_LATITUDE <= latitude <= MAX_LATITUDE and MIN_LONGITUDE <= longitude <= MAX_LONGITUDE:
        print(f'({latitude:.6f}, {longitude:.6f})')