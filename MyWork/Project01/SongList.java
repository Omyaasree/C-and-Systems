package songlist;
// QUESTION: FOR THE NEXT() WHY DID SHE ASK TO RETURN THE CURRENT SONG AND NOT THE CURRENT.NEXT() SONG
// QUESTION FOR ITERATOR WHY IS THERE A NEED FOR ITERATOR BY TITLE AND ITERATOR BY SCORE ? WHEN IT IS GOING TO PRINT
// IN THE SAME ORDER WE INSERTED?
// Question: why do we need the helper methods for the merge() if we just complete 1 method
// the insert() method already does the sorting based on title and the Score for us?
// what happens to the duplicates??? discard or insert left or right?


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * A custom linked list class that stores song nodes.
 * Each node has a reference to the "next by title" node and the "next by score" node.
 * Allows to iterate over the list by title (in increasing alphabetical order)
 * or by score (in decreasing order of the score).
 */
public class SongList {
    private SongNode headByScore; // Head of the list if we want to iterate in the decreasing order of scores.
    private SongNode headByTitle; // Head of the list if we want to iterate in the increasing alphabetical order of the titles.

    /**
     * Read a give csv file and insert songs into the SongList.
     * @param filename name of csv file with songs; the file stores each song as following:
     * Title;Artist;Score
     *
     */
    public void loadSongs(String filename) {
        // FILL IN CODE:
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(";");
                insert(parts[0], parts[1], Integer.parseInt(parts[2]));
            }
        }
        catch (IOException e) {
            System.out.println(e);
        }
    }

    /** Insert a song node with the given song into this linked list,
     * preserving the correct order, and updating both references (the ones connecting nodes according to the title, and the ones connecting nodes according to the score).
     * Before and after the insertion, the nodes should be ordered by title using nextByTitle references
     * and by score, using nextbyScore references.
     * @param title title
     * @param artist artist
     * @param score score (rating)
     */
    public void insert(String title, String artist, int score) {
        // Feel free to write helper methods like insertByTitle, insertByScore
        // FILL IN CODE:
        SongNode newNode = new SongNode(new Song(title, artist, score));
        insertByTitle(newNode);
        insertByScore(newNode);
    }
    public void insertByTitle(SongNode newNode) {
        if (headByTitle == null) {
            headByTitle = newNode;
            return;
        }
        if (newNode.getSong().getTitle().compareTo(headByTitle.getSong().getTitle()) < 0) {
            newNode.setNextByTitle(headByTitle);
            headByTitle = newNode;
            return;
        }
        SongNode curr = headByTitle;
        SongNode prev = null;
        while (curr != null && newNode.getSong().getTitle().compareTo(curr.getSong().getTitle()) > 0) {
            prev = curr;
            curr = curr.getNextByTitle();
        }
        prev.setNextByTitle(newNode);
        newNode.setNextByTitle(curr);
    }

    public void insertByScore(SongNode newNode) {
        if (headByScore == null) {
            headByScore = newNode;
            return;
        }
        if (newNode.getSong().getScore() > headByScore.getSong().getScore()) {
            newNode.setNextByScore(headByScore);
            headByScore = newNode;
            return;
        }
        SongNode curr = headByScore;
        SongNode prev = null;
        while (curr != null && newNode.getSong().getScore() <= curr.getSong().getScore()) {
            prev = curr;
            curr = curr.getNextByScore();
        }
        prev.setNextByScore(newNode);
        newNode.setNextByScore(curr);
    }

    /** Checks if there's a song with given title/artist in the SongList.
     * @param title title of the song
     * @param artist artist of the song
     * @return true if the song is present, and false otherwise
     */
    public boolean containsSong(String title, String artist) {
        // FILL IN CODE:
        SongNode curr = headByTitle;
        SongNode prev = null;
        while(curr != null){
            if(curr.getSong().getTitle().equals(title)){
                return true;
            }
            curr = curr.getNextByTitle();
        }
        return false;
    }

    /** Return a SongList where each song's score falls in [min, max] range.
     * Songs should be sorted in decreasing order of the score.
     *
     * @param min
     * @param max
     * @return SongList that contains songs whose score is >= min, <= max.
     */
    public SongList findSongsWithinScoreRange(int min, int max) {
        SongList result = new SongList();
        // FILL IN CODE:
        if(headByScore == null) return result;

        SongNode curr = headByScore;
        while(curr != null){
            int score = curr.getSong().getScore();
            if(score >= min && score <= max){
                result.insertByTitle(curr);
                result.insertByScore(curr);
            }
            curr = curr.getNextByScore();
        }
        return result;
    }

    /** Merge this song list with the "other" sorted song list and return a new list.
     *  The resulting list should be sorted both by score in decreasing order and by title in increasing alphabetical order.
     * @param other another SongList
     * @return a new SongList that contains songs from both this and other lists.
     */
    public SongList mergeWith(SongList other) {
        SongList merged = new SongList();
        // FILL IN CODE:
        // Feel free to add helper methods like mergeByScore, mergeByTitle
        mergeByTitle(other, merged);
        mergeByScore(other, merged);
        return merged;
    }

    public void mergeByTitle(SongList other, SongList merged) {
        SongNode currA = headByTitle;
        SongNode currB = other.headByTitle;

        while(currB != null) {
            merged.insertByTitle(currB);
            currB = currB.getNextByTitle();
        }

        while(currA != null) {
            merged.insertByTitle(currA);
            currA = currA.getNextByTitle();
        }
    }

    public void mergeByScore(SongList other, SongList merged) {
        SongNode currA = headByScore;
        SongNode currB = other.headByScore;
        while(currB != null) {
            merged.insertByScore(currB);
            currB = currB.getNextByScore();
        }
        while(currA != null) {
            merged.insertByScore(currA);
        }
    }

    /**
     * Return a new SongList containing the top k highest-scoring songs.
     * If k >= the total number of songs, all songs are returned.
     * @param k number of highest scoring songs to return
     * @return song list containing the top k highest-scoring songs
     */
    public SongList findBestKSongs(int k) {
        SongList result = new SongList();
        // FILL IN CODE:
        int length = length();
        int num = 0;
        if(k <= 0) {
            System.out.println("the user input is invalid");
            return new SongList();
        }
        SongNode curr = headByScore;
        if(k >= length){
            while(curr != null){
                result.insertByScore(curr);
                curr = curr.getNextByScore();
            }
        }else{
            while(k > num){
                result.insertByScore(curr);
                curr = curr.getNextByScore();
                num++;
            }
        }
        return result;
    }

    public int length(){
        int lenght = 0;
        if(headByScore == null) return lenght;
        SongNode curr = headByScore;
        while(curr != null){
            lenght += 1;
            curr = curr.getNextByScore();
        }
        return lenght;
    }

    /**
     * Return a new SongList containing the k lowest-scoring songs.
     * Must use the slow/fast pointer approach to find the start of the last k nodes.
     * Not allowed to count nodes or keep track of the size of the list.
     * If k >= total size, return a list with all songs.
     * @param k number of lowest scoring songs to return.
     * @return song list with k lowest-scoring songs
     */
    public SongList findWorstKSongs(int k) {
        SongList result = new SongList();
        // FILL IN CODE:
        int length = length(); // the length of the whole linked list
        int numCheck = 0;

        if(k <= 0 || k > length) {
            System.out.println("the user input is invalid");
            return result;
        }
        SongNode curr = headByScore;

        for(int i = length - 1; i >= 0; i--){
            while(k > numCheck) {
                result.insertByScore(curr);
                curr = curr.getNextByScore();
                numCheck++;
            }
        }
        return result;
    }

    /**
     * An iterator for iterating "by title"
     * @return iterator by title
     */
    public Iterator<Song> iteratorByTitle() {
        return new IteratorByTitle();
    }

    /** An iterator for iterating "by score"
     *
     * @return iterator by score
     */
    public Iterator<Song> iteratorByScore() {
        return new IteratorByScore();
    }

    /* Iterator by Title */
    class IteratorByTitle implements Iterator<Song> {
        private SongNode current = headByTitle;

        @Override
        public boolean hasNext() {
            // FILL IN CODE:
            return current != null;
        }

        /** Return the current song, move the iterator to the "nextByTitle" song node.
         *
         * @return current song
         */
        @Override
        public Song next() {
            // FILL IN CODE:
            if(hasNext()){
                Song song = current.getSong();
                current = current.getNextByTitle();
                return song;
            }else{
                throw new NoSuchElementException(); //  change
            }
        }
    };

    /* Iterator by score. */
    class IteratorByScore implements Iterator<Song> {
        private SongNode current = headByScore;

        @Override
        public boolean hasNext() {
            // FILL IN CODE:
            return current != null;
        }

        /** Return the current Song, and move the iterator to the "nextByScore" node
         *
         * @return current song
         */
        @Override
        public Song next() {
            // FILL IN CODE:
            if(hasNext()){
                Song song = current.getSong();
                current = current.getNextByScore();
                return song;
            }else{
                throw new NoSuchElementException();
            }
        }
    };
}
