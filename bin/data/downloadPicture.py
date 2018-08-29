# coding: UTF-8
import urllib2
from bs4 import BeautifulSoup

station_name = "長岡京駅"
url = "https://search.yahoo.co.jp/image?p=" + station_name

req = urllib2.Request(url)
res = urllib2.urlopen(req)
html = res.read()
print(html)