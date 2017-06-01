import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        # TODO
        self.tokenizer = nltk.tokenize.TweetTokenizer()
        pos = []
        neg = []
        self.positives = pos
        self.negatives = neg
        file = open(positives, "r")
        for line in file:
            if line.startswith(";"):
                line.strip("line")
            else:
                pos.append(line.strip())
        file.close()
        file = open(negatives, "r")
        
        for line in file:
            if line.startswith(";"):
                line.strip("line")
            else:
                neg.append(line.strip())
        file.close()
        

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        # TODO
        score = 0.0
        tokens = self.tokenizer.tokenize(text)
        for token in tokens:
            token = token.lower()
            if token in self.positives:
                score = score+1
            elif token in self.negatives:
                score = score-1
            else:
                score = score
        
        return score
