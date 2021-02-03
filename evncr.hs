-- TODO: IMPLEMENT PER-USER CONFIGURATION FILES.

import Config;
import Control.Concurrent;
import System.Process;
import System.Environment;
import Text.Printf;

thingToInt :: Char -> [Int];
thingToInt theShift = [f theShift | f <- [prefixOne, prefixTwo, meatAndPotato]]

--For all characters X, prefixOne X is equal to the first
--"prefix" of X, e.g., "LATIN" or "ARABIC".
prefixOne :: Char -> Int;
prefixOne theShift
  | shifter < 58 && shifter >= 48 = 129
  | otherwise = 128
  where shifter = fromEnum theShift

--For all characters X, prefixTwo X is equal to the second
--"prefix" of X, e.g., "MAJUSCULE" or "MINUSCULE".
prefixTwo :: Char -> Int;
prefixTwo character
  | shifter < 48 = 0
  | shifter < 58 = 1
  | shifter < 65 = 0
  | shifter < 91 = 3
  | shifter < 97 = 0
  | shifter < 123 = 4
  where shifter = fromEnum character

-- For all characters X, meatAndPotato converts X into the
-- "simplified" ASCII representation of X.
meatAndPotato :: Char -> Int;
meatAndPotato character
  | shifter `elem` [95..122] = (shifter - 32)
  | shifter `elem` [62,93,125] = (shifter - 2)
  | shifter == 41 = 40
  | otherwise = shifter
  where shifter = fromEnum character

toFileName :: Int -> [Char];
toFileName charInt = soundDir ++ (show charInt) ++ ".wav";

outputSound :: [Int] -> IO [String];
outputSound x = threadDelay delay_interChar >> mapM (playFile . toFileName) x;

playFile :: [Char] -> IO String;
playFile filename = threadDelay delay_intraChar >> readProcess "mplayer" [filename] "";

main = getLine >>= \input ->
  print $ map thingToInt input >>
  mapM (outputSound . thingToInt) input;
