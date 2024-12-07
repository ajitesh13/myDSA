from collections import defaultdict, deque

class MusicPlayer:

    def __init__(self):
        self.next_music_id = 1
        self.music_library = {}
        self.song_user_map = defaultdict(set)
        self.user_song_map = defaultdict(deque)

    def add_song(self, song_title):
        if song_title in self.music_library:
            return "Error: Music already in library"

        self.music_library[self.next_music_id] = song_title
        self.next_music_id += 1
        
        return self.next_music_id
    
    def play_song(self, song_id, user_id):
        if song_id not in self.music_library:
            return "Error: Music not added"
        
        self.song_user_map[song_id].add(user_id)

        if user_id not in self.user_song_map:
            self.user_song_map[user_id] = deque(maxlen=3)
        
        if song_id in self.user_song_map[user_id]:
            self.user_song_map[user_id].remove(song_id)
        self.user_song_map[user_id].appendleft(song_id)
        
        
    def print_analytics_summary(self):
        res = []

        for song_id, users in self.song_user_map.items():
            res.append((len(users), self.music_library[song_id]))
        
        res.sort(reverse=True)

        return res
    
    def last_three_played_song_title(self, user_id):
        if user_id not in self.user_song_map:
            return "Error: User not found"
        
        res = []
        for song in self.user_song_map[user_id]:
            res.append(self.music_library[song])
        
        return res

    
music_player = MusicPlayer()
music_player.add_song("ABC")
music_player.add_song("BCD")
music_player.add_song("EDG")
music_player.add_song("UIO")
music_player.add_song("JJY")
music_player.add_song("MKL")
music_player.add_song("ZYZ")

music_player.play_song(1, 1)
music_player.play_song(1, 2)
music_player.play_song(1, 3)
music_player.play_song(2, 2)
music_player.play_song(1, 3)
music_player.play_song(4, 4)
music_player.play_song(3, 3)
music_player.play_song(5, 5)
music_player.play_song(6, 5)
music_player.play_song(7, 5)
music_player.play_song(7, 7)
music_player.play_song(3, 2)

analytics_report = music_player.print_analytics_summary()
print(analytics_report)

recently_played_music = music_player.last_three_played_song_title(2)
print(recently_played_music)
