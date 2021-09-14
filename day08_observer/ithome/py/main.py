from observable import *
from observer import *


if __name__ == '__main__':
    podcast = Podcast('English broadcast')
    student = Student(podcast)

    podcast.notify()

    podcast.name = 'Pop song'
    podcast.notify()
    # heard English broadcast
    # heard Pop song
