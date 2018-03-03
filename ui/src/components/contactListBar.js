import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List from 'material-ui/List';
import ContactListItem from './contactListItem';

const styles = theme => ({
  contactsListBar: {
    overflow: 'auto',
    minHeight: '120px',
    height: 'calc(100vh - 77px)',
    backgroundColor: theme.palette.primary.main,
  },
});

class ContactListBar extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }

  render() {
    return (    
      <Grid item align="center" className={ this.classes.contactsListBar }>
        <List disablePadding>
          {
            this.props.contacts.map((item) => (
              <ContactListItem
                key={item.uid}
                uid={item.uid}
                nickname={item.nickname}
                statusMessage={item.statusMessage}
                avatarSrc={item.avatarSrc}
                connectionStatus={item.connectionStatus}
                userStatus={item.userStatus}
                unreadMessagesCount={item.unreadMessagesCount}
                clickCallback={this.props.contactClickCallback}
              />
            ))
          }          
        </List>
      </Grid>
    );
  }
}

ContactListBar.propTypes = {
  classes: PropTypes.object.isRequired,
  contacts: PropTypes.array,
};

ContactListBar.defaultProps = {
  contacts: [],
}

export default withStyles(styles)(ContactListBar);
