import Config;
import Data.List;
import Control.Monad;
import System.Process;
import Control.Concurrent;

-- | For all 'Character' @k@, @k@ is a representation of an ASCII
-- character.
data Character = Character {
  -- | @prefix1 k@ is the first prefix of @k@, e.g., "LATIN" or
  -- "ARABIC".
  prefix1 :: Int,
  -- | @prefix2 k@ is the second prefix of @k@, e.g., "MAJUSCULE" or
  -- "MINUSCULE".
  prefix2 :: Int,
  -- | @asciiNum k@ is the "meat and potatoes" of @k@, e.g., 
  asciiNum :: Int
} deriving (Eq, Read, Show);

parseCharacter :: Char -> Character;
parseCharacter k = Character {
  prefix1 = prefix1',
  prefix2 = prefix2',
  asciiNum = asciiNum'
  }
  where
  asciiNum' :: Int
  asciiNum'
    | k' `elem` [95..122] = k' - 32
    | k' `elem` [62,93,125] = k' - 2
    | k' == 41 = 40
    | otherwise = k'
  --
  prefix1' :: Int
  prefix1'
    | k' `elem` [49..58] = 129
    | otherwise = 128
  --
  prefix2' :: Int
  prefix2'
    | k' < 48 = 0
    | k' < 58 = 1
    | k' < 65 = 0
    | k' < 91 = 3
    | k' < 97 = 0
    | k' < 123 = 4
  --
  k' :: Int
  k' = fromEnum k;

-- | @defaultCharacter@ is the 'Character' value which @'readSingle'@
-- interprets as a "yo, pause for a bit" signal.
defaultCharacter :: Character;
defaultCharacter = Character {prefix1 = 0, prefix2 = 0, asciiNum = 0};

readSequence :: [Character] -> IO ();
readSequence = mapM_ readSingle . intersperse defaultCharacter;

-- | @readSingle n@ reads @n@.  If @n == 'defaultCharacter'@, then an
-- intercharacter pause is "output".
readSingle :: Character -> IO ();
readSingle k
  | k == defaultCharacter = threadDelay delay_interChar
  | otherwise =
    playFile (prefix1 k) >>
    threadDelay delay_intraChar >>
    playFile (prefix2 k) >>
    threadDelay delay_intraChar >>
    playFile (asciiNum k);

-- | @playFile n@ plays the file whose filename is @n ++ ".wav"@, where
-- the root directory is @'soundDir'@.
playFile :: Int -> IO ();
playFile n = void $ readProcess "mplayer" [soundDir ++ show n ++ ".wav"] [];

main :: IO ();
main = getLine >>= readSequence . map parseCharacter;
