import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import ContactListItem from './contactListItem';

const styles = theme => ({
  profileBarContainer: {
    overflow: 'hidden',
    backgroundColor: theme.palette.primary.main,
    minHeight: '77px',
  },
});

class ProfileBar extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }

  render() {
    return (
      <Grid item align="center" className={ this.classes.profileBarContainer }>
        <ContactListItem
          nickname={ this.props.profileBar.nickname }
          statusMessage={ this.props.profileBar.statusMessage }
          avatarSrc={ this.props.profileBar.avatarSrc }
          userStatus={ this.props.profileBar.userStatus }
          connectionStatus={ this.props.profileBar.connectionStatus }
          clickCallback={ this.props.clickCallback }
        />
      </Grid>
    );
  }
}

ProfileBar.propTypes = {
  classes: PropTypes.object.isRequired,
  profileBar: PropTypes.shape({
    nickname: PropTypes.string,
    statusMessage: PropTypes.string,
    avatarSrc: PropTypes.string,
    userStatus: PropTypes.number,
    connectionStatus: PropTypes.bool,
  }),
  clickCallback: PropTypes.func,
};

ProfileBar.defaultProps = {
  profileBar: {
    nickname: "",
    statusMessage: "",
    avatarSrc: "",
    userStatus: 0,
    connectionStatus: false,
  },
  clickCallback: (() => {}),
}

export default withStyles(styles)(ProfileBar);
