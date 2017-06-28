import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        
        pos_list = []
        f_pos = open(positives)
        pos_list = f_pos.readlines()
        index = 0
        
        # strip
        for word in pos_list:
            pos_list[index] = word.strip(";\n")
            index += 1
        
        # pop those elements that are not words we are looing for
        index_1 = 0
        for word in pos_list:
            if word.startswith(" ") or word == "" :
                pos_list.pop(index_1)
                continue
            pos_list[index_1] = word
            index_1 += 1
        self.positives = pos_list
        f_pos.close()
        
        # same for the negative words
        neg_list = []
        f_neg = open(negatives)
        neg_list = f_neg.readlines()
        index = 0
        # strip
        for word in neg_list:
            neg_list[index] = word.strip(";\n")
            index += 1
        
        index_1 = 0
        for word in neg_list:
            if word.startswith(" ") or word == "" :
                neg_list.pop(index_1)
                continue
            neg_list[index_1] = word
            index_1 += 1
        self.negatives = neg_list
        f_neg.close()
        
    # this text is a string to be analyzed
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        
        # Tokenize the text and use them to analyze
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        
        # initialize scores
        pos = 0
        neg = 0
        
        for token in tokens:
            if token.lower() in self.positives:
                pos += 1
            if token.lower() in self.negatives:
                neg -= 1
        return pos + neg

