import random
import tweepy
import time
import itertools

CONSUMER_KEY = ' ' #Clave del usuario
CONSUMER_SECRET = ' ' #Clave secreta del usuario
ACCESS_TOKEN = ' ' #Clave de la aplicacion
ACCESS_TOKEN_SECRET = ' ' #Clave secreta de la aplicacion

auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_TOKEN, ACCESS_TOKEN_SECRET)
api = tweepy.API(auth)

#Funcion de iteracion
def paginate(iterable, page_size):
    while True:
        i1, i2 = itertools.tee(iterable)
        iterable, page = (itertools.islice(i1, page_size, None),
                list(itertools.islice(i2, page_size)))
        if len(page) == 0:
            break
        yield page
###################################
Lista_amigos=[]
usuario = api.me()
followers = api.followers_ids(screen_name=usuario.screen_name)
tope_api = 100

for pagina_amigos in paginate(followers, tope_api):
    amigos = api.lookup_users(user_ids=pagina_amigos)
    for amigo in amigos:
        Lista_amigos.append(amigo)
usuario_random = random.choice(Lista_amigos)
print (usuario_random.screen_name)

#if:
#	api.update_status(status="@"+usuario_random+ " esto es una prueba de python :)")
#else:
#	api.update_status(status=random.random())

