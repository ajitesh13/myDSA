from bs4 import BeautifulSoup
from requests import get

url = 'https://www.imdb.com/search/title/?groups=top_250&sort=user_rating,desc&start=1&ref_=adv_nxt'
page = get(url)
page_soup = BeautifulSoup(page.text, 'html.parser')

top_movie = page_soup.find_all('div', class_='lister-item-content')
for movie in top_movie:
    movie.h3.a
