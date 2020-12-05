-- TODO: IMPLEMENT PER-USER CONFIGURATION FILES.

import Config;
import Control.Concurrent;
import System.Process;
import System.Environment;
import Text.Printf;

thingToInt :: Char -> [Int];
thingToInt theShift = [(prefixOne theShift), (prefixTwo theShift), (meatAndPotato theShift)];

--For all characters X, prefixTwo X is equal to the first
--"prefix" of X, e.g., "LATIN" or "ARABIC".
prefixOne :: Char -> Int;
prefixOne theShift
  | (shifter < 58) && (shifter >= 48) = 129
  | otherwise = 128
  where shifter = (fromEnum theShift)

--For all characters X, prefixTwo X is equal to the second
--"prefix" of X, e.g., "MAJUSCULE" or "MINUSCULE".
prefixTwo :: Char -> Int;
prefixTwo theShift
  | shifter < 48 = 0
  | shifter < 58 = 1
  | shifter < 65 = 0
  | shifter < 91 = 3
  | shifter < 97 = 0
  | shifter < 123 = 4
  where shifter = (fromEnum theShift)

-- For all characters X, meatAndPotato converts X into the
-- "simplified" ASCII representation of X.
meatAndPotato :: Char -> Int;
meatAndPotato theShift
  | (shifter > 96) && (shifter < 123) = (shifter - 32)
  | shifter `elem` [62,93,125] = (shifter - 2)
  | shifter == 41 = 40
  | otherwise = shifter
  where shifter = (fromEnum theShift)

toFileName :: Int -> [Char];
toFileName theShift = ("/usr/local/share/evncr/sound/" ++ (show theShift) ++ ".wav");

outputSound :: [Int] -> IO [String];
outputSound x = do
  threadDelay delay_interCharacter;
  mapM (playFile . toFileName) x;

playFile :: [Char] -> IO String;
playFile x = do
  threadDelay delay_intraCharacter;
  readProcess "mplayer" [x] "";

main = do
  theInput <- getLine;
  print (map (thingToInt) theInput);
  mapM (outputSound . thingToInt) theInput;
