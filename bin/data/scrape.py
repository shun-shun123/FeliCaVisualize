# coding: UTF-8
import urllib.request
import bs4

station_name = "向日町駅"
url = "https://search.yahoo.co.jp/image/search?ei=UTF-8&fr=sfp_as&aq=-1&oq=&ts=8&p=" + urllib.parse.quote_plus(station_name, encoding="utf-8") + "&meta=vc%3D"

request = urllib.request.Request(url)
response = urllib.request.urlopen(request)
html = response.read()

encoding_list = ["utf-8", "utf_8", "euc_jp", 
                    "euc_jis_2004", "euc_jisx0213", "shift_jis",
                    "shift_jis_2004","shift_jisx0213", "iso2022jp",
                     "iso2022_jp_1", "iso2022_jp_2", "iso2022_jp_3",
                    "iso2022_jp_ext","latin_1", "ascii"]

for enc in encoding_list:
    try:
        html.decode(enc)
        break
    except:
        enc = None

print(enc)
if enc != None:
    print(html.decode(enc))
    html = html.decode(enc)

resources = []

# BeautifulSoupオブジェクト作成
soup = bs4.BeautifulSoup(html)
# htmlのすべてのaタグの中のhref属性の内容を取得
elements = soup.findAll('img')
print(type(elements))
num = 0
for e in elements:
    request = urllib.request.urlopen(e['src'])
    num += 1
    f = open(str(num) + "pic.png", "wb")
    f.write(request.read())
    f.close()
