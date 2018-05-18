import requests
from bs4 import BeautifulSoup
from textblob import TextBlob

URL = "https://www.gsmarena.com/"

def get_mob_link(URL):
    user_brand = input("Enter Brand Name(First Letter Capital): ")
    req = None
    try:
        req = requests.get(URL)
    except requests.exceptions.RequestException as e:
        print('exception caught', e)
    mob_links = []
    if req.status_code == 200:
        soup = BeautifulSoup(req.content, "lxml")
        a_tag = soup.find("a", string = user_brand)
        if a_tag == None:
            a_tag = soup.find("a", string = user_brand.upper())
        if a_tag is not None:
            get_paging_links(URL+a_tag['href'])


def get_paging_links(url):
    url_list = [url]
    req = None
    try:
        req = requests.get(url)
    except requests.exceptions.RequestException as e:
        print('exception caught', e)
    if req.status_code == 200:
        soup = BeautifulSoup(req.content, "lxml")
        div_tag = soup.find("div", {'class': 'nav-pages'})
        a_tags = div_tag.find_all("a")
        for a_tag in a_tags:
            url_list.append(URL+a_tag['href'])
        get_all_links(url_list)


def get_all_links(url_list):
    a_tags_link = []
    req = None
    for url in url_list:
        try:
            req = requests.get(url)
        except requests.exceptions.RequestException as e:
            print('exception caught', e)
        if req.status_code == 200:
            soup = BeautifulSoup(req.content, "lxml")
            div_tag = soup.find("div", {'class':'makers'})
            ul_tag = div_tag.findChild()
            a_tags = ul_tag.find_all("a")
            for a_tag in a_tags:
                a_tags_link.append(URL+a_tag['href'])
    get_all_comments(a_tags_link)

def get_comments_from_page(url):
    commnt_list = []
    req = None
    try:
        req = requests.get(url)
    except requests.exceptions.RequestException as e:
        print('exception caught', e)
    if req.status_code == 200:
        soup = BeautifulSoup(req.content, 'lxml')
        cmnt_p = soup.find_all('p', {'class':'uopin'})
        for cmnt in cmnt_p:
            commnt_list.append(cmnt.text)
        return commnt_list


def return_evaluation(comments):
    positive_polarity = []
    for comment in comments:
        blob = TextBlob(comment)
        if blob.sentiment.polarity >= 0:
            positive_polarity.append(blob.sentiment.polarity)
    if len(positive_polarity) >= len(comments)/2:
        return 1
    else:
        return 0


def get_all_comments(url_list):
    print(len(url_list))
    evaluate_res = []
    for url in url_list:
        comments = get_comments_from_page(url)
        if return_evaluation(comments) == 1:
            evaluate_res.append(url)
    print(len(evaluate_res))


def main():
    get_mob_link(URL)


if __name__ == "__main__":
    main()