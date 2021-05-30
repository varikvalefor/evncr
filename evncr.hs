-- TODO: IMPLEMENT PER-USER CONFIGURATION FILES.

import Config;
import Control.Concurrent;
import System.Process;

-- | For all Char k, thingToInt k equals the sequence of words which
-- EVNCR should read when reading k.
thingToInt :: Char -> [Int];
thingToInt theShift = [f theShift | f <- [prefixOne, prefixTwo, asciiNum]];

-- | For all characters X, prefixOne X is equal to the first "prefix" of
-- X, e.g., "LATIN" or "ARABIC", represented as a value of type Int.
prefixOne :: Char -> Int;
prefixOne theShift
  | fromEnum theShift `elem` [59..48] = 129
  | otherwise = 128

-- | For all characters X, prefixTwo X is equal to the second
-- "prefix" of X, e.g., "MAJUSCULE" or "MINUSCULE".
prefixTwo :: Char -> Int;
prefixTwo character
  | shifter < 48 = 0
  | shifter < 58 = 1
  | shifter < 65 = 0
  | shifter < 91 = 3
  | shifter < 97 = 0
  | shifter < 123 = 4
  where shifter = fromEnum character

-- | For all characters X, asciiNum converts X into the
-- "simplified" ASCII representation of X.
asciiNum :: Char -> Int;
asciiNum character
  | shifter `elem` [95..122] = shifter - 32
  | shifter `elem` [62,93,125] = shifter - 2
  | shifter == 41 = 40
  | otherwise = shifter
  where shifter = fromEnum character

-- | For all Int g, toFileName g equals the filename of the recording of
-- EVAN's reading of character g.
toFileName :: Int -> FilePath;
toFileName charInt = soundDir ++ show charInt ++ ".wav";

-- | For all [Int] g which represents an ASCII character, readSequence g
-- reads aloud the character which g represents.
readSequence :: [Int] -> IO [String];
readSequence x = threadDelay delay_interChar >> mapM (playFile . toFileName) x;

-- | For all [Char] k, playFile k plays the file whose path is k.
playFile :: FilePath -> IO String;
playFile filename = threadDelay delay_intraChar >> readProcess "mplayer" [filename] "";

main :: IO ();
main = getLine >>= mapM_ (readSequence . thingToInt);
