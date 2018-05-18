import requests
from bs4 import BeautifulSoup

pages_list = []
news_links = []
count = 0

def get_all_pages_strings(URL):
    req = requests.get(URL)
    if req.status_code == 200:
        parse_obj = BeautifulSoup(req.content, "lxml")
        a_temp = parse_obj.find("a",{"class":"page-link"})
        if a_temp['href'] not in pages_list:
            pages_list.append(a_temp['href'])
        temp =  parse_obj.find_all("span", {"class":"page-link"})
        if len(temp) == 1:
            for i in temp:
                temp1 = i.findChild()
                return temp1['href']
        else:
            temp = temp[1:]
            for i in temp:
                temp1 = i.findChild()
                return temp1['href']
        #print(pages_list)


def go_next_page(URL, userstr):
    for i in range(6):
        URL = get_all_pages_strings(URL)
    for each_link in pages_list:
        get_all_news_links(each_link, userstr)

def get_all_news_links(URL, userstr):

    req = requests.get(URL)
    if req.status_code == 200:
        parser_obj = BeautifulSoup(req.content, "lxml")
        a_tag_list = parser_obj.find_all("a")
        for a_tag in a_tag_list:
            if userstr in a_tag.get_text():
                news_links.append(a_tag["href"])



def main():
    URL = "https://propakistani.pk/category/sports/"
    userstr = input("Enter Word to find : ")
    #url_list = get_all_news_links(URL, userstr)
    #print(url_list)
    go_next_page(URL, userstr)
    print(news_links)


if __name__ == "__main__":
    main()
