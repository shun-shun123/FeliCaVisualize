import urllib.request


url = 'https://script.google.com/macros/s/AKfycbymy6K0KVO_OqSkv6TNFxBqmon9g_jCfPPfNXRH7lwOciR4ETY/exec'

with urllib.request.urlopen(url) as res:
    html = res.read().decode('UTF-8')
    print(html)