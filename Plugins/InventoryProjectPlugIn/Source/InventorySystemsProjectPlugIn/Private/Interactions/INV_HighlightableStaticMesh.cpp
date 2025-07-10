// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/INV_HighlightableStaticMesh.h"

void UINV_HighlightableStaticMesh::Highlight_Implementation()
{
	SetOverlayMaterial(HighlightMaterial); 
}

void UINV_HighlightableStaticMesh::UnHighlight_Implementation()
{
	SetOverlayMaterial(nullptr);
}
