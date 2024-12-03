# We are building a cloud-based music player, like Spotify.
# Let's start with the following functionality:

# * `add_song (song_title [string])`
#    - A song is given an incremental integer ID when it's added, starting with 1

# * `play_song (song_ID [integer], user_ID [integer])`
#    - Assume any user ID is valid, and that the given song ID will have been added

# * `print_analytics_summary ()`
#    - This is used for a report, created once per day for our company's Analytics department.
#    - The summary should be sorted (descending) by the number of unique users who have played each song.
#    - The summary should include the song titles, and the number of unique users, but the formatting does not matter.

# For our MVP, consider performance as we will eventually support millions of songs and users.
# However, let's not worry about thread safety or persistence for now - store data in memory.

# We now want to allow users to see their most recently played songs.

# Let's implement the following function:

#    * `last_three_played_song_titles (user_ID [integer])`
#       * Returns the titles of the last three unique played songs for the given user (ordered, most recent first)

# Let's prioritize solving the problem for the last three played songs for now.
# We can tackle extensibility at a later stage.

# After running the new function with the plays from the previous example,
# the summary should output as follows for user ID 1 (in order):

# Hello, Goodbye
# Stairway to Heaven
# Bohemian Rhapsody

from collections import defaultdict

class Musicplayer:
    
    def __init__(self):
        self.song_id = 1
        self.song_collection = {}
        self.song_played = defaultdict(set)
        self.user_song = defaultdict(list)
    
    def add_song(self, song_title):
        self.song_collection[self.song_id] = song_title
        self.song_id += 1
    
    def play_song(self, song_id, user_id):
        self.song_played[song_id].add(user_id)
        self.user_song[user_id].append(song_id)
    
    def print_analytics_summary(self):
        result = []
        for songid in self.song_played.keys():
            result.append((len(self.song_played[songid]), self.song_collection[songid]))
        
        for no_of_user, song_name in sorted(result):
            print(f"Song Name: {song_name} Played by: {no_of_user}")
    
    def last_three_played_song_titles(self, user_id):
        result = []

        if len(self.user_song[user_id]) <= 3:
            result.extend(self.user_song[user_id])
        else:
            result.extend(self.user_song[user_id][:3])
        
        for song in result:
            print(self.song_collection[song])

spotify = Musicplayer()
spotify.add_song("abc")
spotify.add_song("bcd")
spotify.add_song("def")
spotify.play_song(1, 1)
spotify.play_song(1, 2)
spotify.play_song(2, 2)
spotify.play_song(3, 3)
spotify.play_song(2, 3)
spotify.print_analytics_summary()
spotify.last_three_played_song_titles(3)

# deque can be added for storage optimisation