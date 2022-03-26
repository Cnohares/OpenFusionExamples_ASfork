#pragma once

inline void FindPath(LPRDATA rdPtr, Coord start, Coord destination, bool forceFind, bool useRealCoord, const wstring& saveName) {
	if (useRealCoord) {
		start = rdPtr->pFTW->GetGirdCoord(start);
		destination = rdPtr->pFTW->GetGirdCoord(destination);
	}

	if (!forceFind) {
		rdPtr->pFTW->Find(start, destination, rdPtr->diagonal);
	}
	else {
		rdPtr->pFTW->ForceFind(start, destination, rdPtr->diagonal);
	}

	if (saveName != L"") {
		rdPtr->pFTW->SaveLastPath(saveName);
	}
}