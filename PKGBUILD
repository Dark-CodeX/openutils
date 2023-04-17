pkgname="openutils-date_time"
pkgver="1.1.0"
pkgrel="1"
pkgdesc="Date and time classes for C++."
arch=("x86_64" "i686")
conflicts=('openutils-date_time')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/date.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/time.hh")

sha512sums=(
	"c1c6cce17ccaa33f1c0b8e495de67bd62e2c4170d63c8066cf7c52fddfebcbbfc8f68b0c5d8590a96b182c1b3a999ffaf8ee903be4de53278f53fea203a69b57"
	"87a909a744c9906dd6429348fb9ccefaccd276d6641726b54b277a0a74246c622da3bb438553c9222d7a839f4c875bd900cece4343a9c97672ad6532a6508451")

package() {
	echo "Date and time classes for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/date-time"
	cp "${srcdir}/date.hh" "${pkgdir}/usr/include/openutils/date-time/date.hh"
	cp "${srcdir}/time.hh" "${pkgdir}/usr/include/openutils/date-time/time.hh"
	echo "Done!"
}
