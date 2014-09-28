// This file is part of RSS Guard.
//
// Copyright (C) 2011-2014 by Martin Rotter <rotter.martinos@gmail.com>
//
// RSS Guard is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// RSS Guard is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with RSS Guard. If not, see <http://www.gnu.org/licenses/>.

#include "gui/styleditemdelegatewithoutfocus.h"


StyledItemDelegateWithoutFocus::StyledItemDelegateWithoutFocus(QObject *parent) : QStyledItemDelegate(parent) {
}

StyledItemDelegateWithoutFocus::~StyledItemDelegateWithoutFocus() {
}

void StyledItemDelegateWithoutFocus::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
  QStyleOptionViewItemV4 itemOption(option);

  if (itemOption.state & QStyle::State_HasFocus) {
    itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
  }

  QStyledItemDelegate::paint(painter, itemOption, index);
}